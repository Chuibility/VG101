# Reversi

A simple reversi game.

It seems to be a traditional VG101 lab in JI.

You can find the introduction in reversi.pdf

## Tasks

Your task is writing a game named reversi and an AI of it.

The input and output format is shown in the pdf file.

You need to use macro definition to decide SIZE (the length of the chessboard) as follow:

`#define SIZE 8`

Write an AI of this game in your code. Your AI should not be too stupid and the algorithm at least should be reasonable.

## Introduction

See [Reversi - Wikipedia](https://en.wikipedia.org/wiki/Reversi)

> Reversi is a strategy board game for two players, played on an 8×8 uncheckered board. There are sixty-four identical game pieces called disks (often spelled "discs"), which are light on one side and dark on the other. Players take turns placing disks on the board with their assigned color facing up. During a play, any disks of the opponent's color that are in a straight line and bounded by the disk just placed and another disk of the current player's color are turned over to the current player's color.

## Algorithm

### Depth-First-Search (improved by alpha-beta-cutoff)

Wrote by tc-imba

The algorithm use a game tree and an evaluation function to judge where to put the chess. Minimax principle is the main principle in a game tree, though it's not the best solution to the problem. To improve the efficienty, alpha-beta-cutoff is applied to minimize the redundance。
