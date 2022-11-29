from sklearn import datasets
import matplotlib.pyplot as plt
import numpy as np
import sklearn
iris = datasets.load_iris()

def main():
    
    data = iris['data']
    target = iris['target']
    # x = np.linspace(0, 5, num=1000)
    # unit_vector = (3/5, 4/5)
    # threshold = 1.6
    # ind = []
    # print(data[:,3])
    # print(range(len(data[:,3])))
    # print(len(data))
    # for i in range(len(data[:,3])):

    #     if(np.dot( (data[:,2][i], data[:,3][i]),unit_vector,) < threshold):
    #         ind.append(i)
    # plt.plot(x, (-3 * x /4) + 2 )
    # plt.scatter(data[:,2], data[:,3], marker=".", c=target)
    # plt.scatter(data[ind,2], data[ind,3], marker="*")

    # plt.axis('equal')
    # plt.show()
    bc = datasets.load_breast_cancer()
    test_ind = np.random.randint(0, len(target), round(len(target)/5))
    train_ind = np.setdiff1d(range(len(target)), test_ind)  
    from sklearn.neighbors import KNeighborsClassifier

    neigh = KNeighborsClassifier(n_neighbors=1)
    neigh.fit(data[train_ind], target[train_ind])
    predicted = neigh.predict(data[test_ind])
    print(sklearn.metrics.confusion_matrix(target[test_ind], predicted))
    pass


if __name__ == '__main__':
    main()
    # test