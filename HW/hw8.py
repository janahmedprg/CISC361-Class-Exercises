import numpy as np

Alloc = np.array([[3, 0, 1, 4],\
                  [2, 2, 1, 0],\
                  [3, 1, 2, 1],\
                  [0, 5, 1, 0],\
                  [4, 2, 1, 2]])
Max = np.array([[5, 1, 1, 7],\
                [3, 2, 1, 1],\
                [3, 3, 2, 1],\
                [4, 6, 1, 2],\
                [6, 3, 2, 5]])

Need = Max - Alloc
Available = np.array([1, 0, 0, 2])
# Request = np.array([0, 4, 2, 0])
Work = Available
Finish = [False, False, False, False, False]

# if all(Request<=Need[1]):
#     Available -= Request
#     Alloc[1] += Request
#     Need[1] -= Request
# else:
#     print("Must wait.")

while True:
    if False not in Finish:
        break
    flag = True
    for i in range(5):
        if Finish[i] == False and all(Need[i]<=Work):
            Work += Alloc[i]
            Finish[i] = True
            flag = False
            print(i,Work)
    if flag:
        break

print("Finished processes vector (True means done)")
print(Finish)
print("Is state safe:",all(Finish))