# encoding=utf8
import random
import math
import numpy as np


class QTable:
    steps = []

    def __init__(self, steps=None):
        if steps is not None:
            self.steps = steps

    def add(self, state_from, state_to, cost=0):
        self.steps.append([state_from, state_to, cost])

    def moviment_is_possible(self, state_from, state_to):
        for entry in self.steps:
            if QLearning.match_state(state_from, entry[0]) and QLearning.match_state(state_to, entry[1]):
                return True

        return False

    def update(self, state_from, state_to, cost):
        for index, step in enumerate(self.steps):
            if QLearning.match_state(step[0], state_from) and QLearning.match_state(step[1], state_to):
                self.steps[index][2] = cost

    def get_cost(self, state_from, state_to):
        for index, step in enumerate(self.steps):
            if QLearning.match_state(step[0], state_from) and QLearning.match_state(step[1], state_to):
                return self.steps[index][2]

    def get_maximum_qvalue(self, state):
        qentries = []
        qvalues = []

        for index, entry in enumerate(self.steps):
            if QLearning.match_state(state, entry[0]):
                qentries.append(entry[1])
                qvalues.append(entry[2])

        return max(qvalues)

    def get_maximum_qvalue_state(self, state):
        qentries = []
        qvalues = []

        for index, entry in enumerate(self.steps):
            if QLearning.match_state(state, entry[0]):
                qentries.append(entry[1])
                qvalues.append(entry[2])

        return qentries[qvalues.index(max(qvalues))]


class QLearning:
    environment = []
    gamma = 0.8
    qtable = QTable()
    rtable = []
    states = []  # Possible states
    goal_state = None
    current_state = None

    def __init__(self, environment, goal_state=[0, 0], gamma=0.8):
        self.gamma = gamma
        self.goal_state = goal_state
        self.environment = environment

        for xpos, line in enumerate(self.environment):
            for ypos, value in enumerate(line):
                if value is 0:
                    self.states.append([xpos, ypos])

        for state in self.states:
            for possible in self.get_next_possible_actions(state):
                self.qtable.add(state, possible, 0)

        # Current state is the start by default
        self.current_state = self.states[0]

        # R-matrix
        # self.rtable = np.zeros(shape=(len(self.states), len(self.states)))

    def set_goal_state(self, state):
        self.goal_state = state

    def reward_for_position(self, position):

        for i, v in enumerate(self.rtable):
            if self.match_state(v[0], position):
                return v[1]

        return 0

    @staticmethod
    def match_state(a, b):
        return a[0] == b[0] and a[1] == b[1]

    def get_state_by_position(self, x, y):
        for pos, s in enumerate(self.states):
            if s[0] == x and s[1] == y:
                return True, self.states[pos]

        return False, []

    def get_next_possible_actions(self, state):

        check = [
            [state[0] + 1, state[1]],
            [state[0] - 1, state[1]],
            [state[0], state[1] + 1],
            [state[0], state[1] - 1],
        ]

        nexts = []

        for s in check:
            if self.get_state_by_position(s[0], s[1]) and s in self.states:
                nexts.append(s)

        return nexts

    def train(self, episodes=2000):
        # Episode
        for ep in range(episodes):
            print('Episode: ', ep)
            current_state = random.choice(self.states)

            while not self.match_state(current_state, self.goal_state):
                possible_actions = self.get_next_possible_actions(current_state)
                next_state = random.choice(possible_actions)

                # Update q-matrix
                qvalue = self.qtable.get_cost(current_state, next_state)
                maxvalue = self.qtable.get_maximum_qvalue(next_state)
                rvalue = 100 if self.match_state(next_state, self.goal_state) else 0
                cost = rvalue + self.gamma * maxvalue

                self.qtable.update(current_state, next_state, cost)
                current_state = next_state

            if ep is 50:
                self.gamma = 0.5

            if ep is 150:
                self.gamma = 0.1

    def print_environment(self, path=[], pmark="*", wmark="#", fmark="~"):
        env = self.environment

        for xpos, line in enumerate(env):
            for ypos, value in enumerate(line):
                env[xpos][ypos] = wmark if value == 1 else fmark

        for step in path:
            env[step[0]][step[1]] = pmark

        print(np.matrix(env))

    def walk(self, goal_state=None):
        steps = []
        next_state = self.current_state

        if goal_state is None:
            goal_state = self.goal_state

        while not self.match_state(next_state, goal_state) and len(steps) < 25:
            steps.append(next_state)
            next_state = self.qtable.get_maximum_qvalue_state(next_state)

        steps.append(goal_state)
        return steps


if __name__ == "__main__":
    mapa = [
        [0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0],
        [0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0],
        [0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0],
        [0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0],
        [0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0],
        [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0]
    ]

    walkto = [
        [4, 4],
        [4, 10],
        [8, 17]
    ]

    qlearner = QLearning(mapa, [4, 4])
    qlearner.print_environment(path=walkto)
    qlearner.train(episodes=150)
    steps = qlearner.walk([4, 4])
    qlearner.print_environment(path=steps)
    # for w in walkto:
    #     qlearner.print_environment(path=qlearner.walk(goal_state=w))

    # path = qlearner.walk()
    # qlearner.print_environment(path=[
    #     [0, 0], [1, 0], [2, 0]
    # ])
