#!/bin/bash

# URLを定義
url1="https://shibaura-it.zoom.us/j/94036102374?pwd=KzJYQUFPVXRKS2p4d0ZIVjVKb1JGUT09"

# URL(scomb)を定義
url2="https://scombz.shibaura-it.ac.jp/lms/course?idnumber=202303SU0445322001"

# WindowsのデフォルトブラウザでURLを開く
cmd.exe /C start "$url1"

# WindowsのデフォルトブラウザでURLを開く
cmd.exe /C start "$url2"

# WSL内のユーザーフォルダパスを取得
wsl_user_folder_path=$(wslpath -w "/home/iroha/clanguage")

# WindowsのエクスプローラーでWSL内のフォルダを開く
explorer.exe "$wsl_user_folder_path"
