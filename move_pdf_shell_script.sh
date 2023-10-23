#!/bin/bash

# 移動元のディレクトリ
src_dir="/mnt/c/Users/M8763/Desktop"

# 移動先のディレクトリ
dest_dir="/home/iroha/clanguage"

# 移動するファイル名に含まれる文字列
target_string="情報処理"

# 移動元のディレクトリにある、ファイル名に指定した文字列が含まれるファイルを一括で移動する
mv "$src_dir"/*"$target_string"* "$dest_dir"