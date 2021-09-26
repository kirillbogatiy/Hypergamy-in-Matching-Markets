import matplotlib.pyplot as plt
import numpy as np


def main():
    file = open("matching.txt", "r")
    pairs = [[i for i in line.strip().split()] for line in file]
    file.close()
    
    match = {}
    
    manNum = 0
    womanNum = 0
    
    for pair in pairs:
        if pair[0][0] == 'm':
            manNum += 1
        else:
            womanNum += 1
        match[pair[0]] = pair[1]
    
    men = ['m' + str(i) for i in range(manNum - 1, -1, -1)]
    women = ['w' + str(i) for i in range(womanNum - 1, -1, -1)]
    
    isManSingle, isWomanSingle = [], []

    for man in men:
        isManSingle.append(int(match[man] == man))

    for woman in women:
        isWomanSingle.append(int(match[woman] == woman))

    N = len(isManSingle)
    C = 16
    xs = np.arange(N)
    ys = np.array(isManSingle)
    chunks = np.split(xs, C)
    plt.plot(np.mean(chunks, axis=1), np.mean([ys[ch] for ch in chunks], axis=1), '.', mew=10, ms=20)
    plt.show()

    cntPairs = 0

    sumMan = 0

    for man in men:
        if match[man] != man:
            sumMan += 100 - int(man[1:]) / len(men) * 100
            cntPairs += 1


    sumWoman = 0

    for woman in women:
        if match[woman] != woman:
            sumWoman += 100 - int(woman[1:]) / len(women) * 100


    outputFile = open("answer.txt", "w")

    print((sumMan - sumWoman) / cntPairs, file=outputFile)


main()