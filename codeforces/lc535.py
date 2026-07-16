# pretty hard problem and I had  no idea how to begin s0lving this shit WTF !!!

import sys 
import os 
import shutils
import argparse


class Codec:
    def __init__(self):
        self.encodeMap = {}
        self.decodeMap = {}
        self.base = "http://tinyurl.com/"


    def encode(self, longUrl: str) -> str:

        if longUrl not in self.encodeMap:
            shortUrl = self.base + str(len(encodeMap)+1)
            self.encodeMap[longUrl] = shortUrl
            self.decodeMap[shortUrl] = longUrl

        return self.encodeMap[longUrl]


    def decode(self, shortUrl: str) -> str:

        return self.decodeMap[shortUrl]
