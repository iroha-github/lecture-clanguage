#!/bin/bash

# URLを定義
url1="https://drive.google.com/drive/u/1/folders/10_-noD0SkcMS--xg1Fqstjh-JMkt0bbn"

# WindowsのデフォルトブラウザでURLを開く
cmd.exe /C start "$url1"

# WSL内のユーザーフォルダパスを取得
wsl_user_folder_path=$(wslpath -w "/home/iroha/clanguage")

# WindowsのエクスプローラーでWSL内のフォルダを開く
explorer.exe "$wsl_user_folder_path"
