
# iterate the folder structure from a base dir.

# find all the .vscode dirs

# make the folder path and copy the .vscode folder 

import os
import argparse
import shutil

def copy_vscode(path, backup_path):
    for (dirpath, dirnames, filenames) in os.walk(path):
        if '.vscode' in dirnames:
            print(f'{dirpath} {dirnames} {filenames} ')
            src = os.path.join(dirpath, '.vscode')
            
            dst = os.path.join(backup_path, os.path.relpath(src, path))

            print(f'{src} {dst}')
            shutil.copytree(src,dst)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("path")
    parser.add_argument("backup_path")

    args = parser.parse_args()

    copy_vscode(args.path, args.backup_path)

if __name__ == '__main__':
    main()