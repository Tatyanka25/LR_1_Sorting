import matplotlib.pyplot as plt
plt.plot([0,0,0.002, 0.219, 28.720, 5653.005], [10,100,1000,10000,100000, 1000000], color='green', label = 'Bubble Sort')
plt.plot([0,0,0.001, 0.042, 3.421, 807.110], [10,100,1000,10000,100000,1000000], color='pink', label = 'Insertion Sort')
plt.plot([0.002,0,0,0.002,0.019,0.150], [10,100,1000,10000,100000,1000000], color='purple', label = 'Quick Sort')
plt.xlabel('t, мс') #Подпись для оси х
plt.ylabel('Size of array, млн') #Подпись для оси y
plt.title('Sorting time') #Название
plt.legend()
plt.show()
