#!/usr/bin/env bash

name="rack"

tmux new-session -d -s $name -n stack
tmux send-keys -t $name:0 "cd r && nvim stack" C-m
tmux new-window -t $name:1 -n rev
tmux send-keys -t $name:1 "cd r && nvim rev" C-m
tmux new-window -t $name:2 -n todo
tmux send-keys -t $name:2 "cd o && nvim o" C-m
