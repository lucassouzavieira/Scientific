import numpy as np
import matplotlib.pyplot as plt


class KMeans:
    """
    K-means cluster
    """

    def __init__(self, k=2, tol=0.001, max_iter=300):
        self.k = k
        self.tol = tol
        self.max_iter = max_iter
        self.centroids = {}

    def fit(self, data):

        for i in range(self.k):
            self.centroids[i] = np.array(data[i])

        for i in range(self.max_iter):
            self.classifications = {}

            for j in range(self.k):
                self.classifications[j] = []

            for featureset in data:
                distances = [np.linalg.norm(featureset - self.centroids[centroid]) for centroid in self.centroids]
                classification = distances.index(min(distances))
                self.classifications[classification].append(featureset)

            previous_centroids = dict(self.centroids)

            for classification in self.classifications:
                self.centroids[classification] = np.average(self.classifications[classification], axis=0)

            optimized = True

            for c in self.centroids:
                original_centroid = previous_centroids[c]
                current_centroid = self.centroids[c]

                if np.sum((current_centroid - original_centroid) / original_centroid * 100.0) > self.tol:
                    optimized = False

            if optimized:
                break

    def predict(self, data):
        distances = [np.linalg.norm(data - self.centroids[centroid] for centroid in self.centroids)]
        classification = distances.index(min(distances))
        return classification

    def plot_classification(self):
        colors = 10 * ["g", "r", "c", "b", "k"]

        # Centroides
        for centroid in self.centroids:
            plt.scatter(self.centroids[centroid][0], self.centroids[centroid][1],
                        marker="o", color="k", s=50, linewidths=2)

        # Classificacoes
        for classification in self.classifications:
            color = colors[classification]
            for featureset in self.classifications[classification]:
                plt.scatter(featureset[0], featureset[1], marker="x", color=color, s=50, linewidths=2)

        plt.show()


class Data:
    """
    Reads data from CSV
    """

    def __init__(self, filepath):
        self.file = open(filepath, "r")

    def get_data(self):
        data = []

        for line in self.file:
            try:
                linedata = line.split(",")
                data.append(np.array([float(linedata[1]), float(linedata[2])]))
            except ValueError:
                continue

        return data

    def plot(self):
        for featureset in self.get_data():
            plt.scatter(featureset[0], featureset[1],
                        marker="x", color="k", s=25, linewidths=2)

        plt.show()


if __name__ == "__main__":
    data_object = Data("data.csv")

    data_object.plot()
    # cluster = KMeans(k=4)
    # cluster.fit(data_object.get_data())
    # cluster.plot_classification()
