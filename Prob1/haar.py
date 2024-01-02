import numpy as np
import cv2
import argparse
import math

def normalize(img):
    new_img = (img - img.min()) / (img.max() - img.min()) * 255.0
    return new_img

def haar_wavelet_transform(img, depth=1):
    """
    2D Haar wavelet transform implementation.
    """
    new_img = np.copy(img)
    
    height, width = img.shape

    for _ in range(depth):
        # Make Fig1b
        low_freq = np.zeros((height // 2, width))
        high_freq = np.zeros((height // 2, width))
        for i in range(height // 2):
            low_freq[i, :] = (img[2*i, :] + img[2*i + 1, :]) / math.sqrt(2)
            high_freq[i, :] = (img[2*i, :] - img[2*i + 1, :]) / math.sqrt(2)

        # Make Fig1c temp 
        LL = np.zeros((height // 2, width // 2))
        LH = np.zeros((height // 2, width // 2))
        HL = np.zeros((height // 2, width // 2))
        HH = np.zeros((height // 2, width // 2))
        for j in range(width // 2):
            LL[:, j] = (low_freq[:, 2*j] + low_freq[:, 2*j + 1]) / math.sqrt(2)
            LH[:, j] = (low_freq[:, 2*j] - low_freq[:, 2*j + 1]) / math.sqrt(2)
            HL[:, j] = (high_freq[:, 2*j] + high_freq[:, 2*j + 1]) / math.sqrt(2)
            HH[:, j] = (high_freq[:, 2*j] - high_freq[:, 2*j + 1]) / math.sqrt(2)

        # Apply 1c to result image
        new_img[:height//2, :width//2] = LL
        new_img[:height//2, width//2:width] = LH
        new_img[height//2:height, :width//2] = HL
        new_img[height//2:height, width//2:width] = HH

        # For the deeper 
        height //= 2
        width //= 2

        img = LL

    new_img = normalize(new_img)
    
    return new_img



def main(args):
    image = cv2.imread(args.input, cv2.IMREAD_GRAYSCALE).astype(np.float32)
    transformed_image = haar_wavelet_transform(image, depth=args.depth)
    cv2.imwrite(args.output, transformed_image)

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--input', type=str, required=True, help='input image path')
    parser.add_argument('--output', type=str, required=True, help='output image path')
    parser.add_argument('--depth', type=int, required=True, help='depth of Haar wavelet transform')
    args = parser.parse_args()
    main(args)