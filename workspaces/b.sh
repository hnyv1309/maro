#!/usr/bin/env bash

name="stem"

cd ~/coding/stem
tmux new-session -d -s $name -n codin
tmux new-window -t $name:1 -n git
tmux send-keys -t $name:1 "git status" C-m
tmux new-window -t $name:2 -n host
tmux send-keys -t $name:2 "python -m http.server" C-m
tmux new-window -t $name:3 -n todo
tmux send-keys -t $name:3 "nvim .todo" C-m
