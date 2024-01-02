import copy
original_list = [[1 , 2, 3] , [4 , 5, 6] , [7 , 8 , 9]]
copy_1 = copy.copy(original_list)
copy_2 = copy.deepcopy(original_list)
copy_3 = list(original_list)
copy_4 = original_list[:]
copy_5 = [row[:] for row in original_list]
copy_1[0][0]= 100
copy_2[0][1]= 200
copy_3[0][2]= 300
copy_4[1][0]= 400
copy_5[1][1]= 500
print (" Copy 1:" , copy_1 )
print (" Copy 2:" , copy_2 )
print (" Copy 3:" , copy_3 )
print (" Copy 4:" , copy_4 )
print (" Copy 5:" , copy_5 )