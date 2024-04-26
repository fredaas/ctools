#!/usr/bin/env python3

import zlib

def main():
    with open("strings.txt") as fh:
        data = fh.read().strip().split("\n")
        for item in data:
            print(hex(zlib.crc32(bytes(item, "utf-8"))))

if __name__ == '__main__':
    main()
