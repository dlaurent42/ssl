# MD5 / SHA[224,256,384,512]

#### Final Mark: 125 / 125


## Introduction by 42 School

This is what Wikipedia has to say on the subject of cryptographic hash functions:

A cryptographic hash function is a special class of hash function that has certain propertiesi which make it suitable for use in cryptography. It is a mathematical algorithm that maps data of arbitrary size to a bit string of a fixed size. It is designed to also be a one-way function, that is, a function which is infeasible to invert. The only way to
recreate the input data from an ideal cryptographic hash function’s output is to attempt a brute-force search of possible inputs to see if they produce a match, or use a rainbow table of matched hashes. Bruce Schneier has called one-way hash functions "the workhorses of modern cryptography". The input data is often called the message, and the output (the hash value or hash) is often called the message digest or simply the digest.

The ideal cryptographic hash function has five main properties:
- it is deterministic, so the same message always results in the same hash
- it is quick to compute the hash value for any given message
- it is infeasible to generate a message from its digest except by trying all possible messages
- a small change to a message should change the hash value so extensively that the
new hash value appears uncorrelated with the old hash value
- it is infeasible to find two different messages with the same hash value

Cryptographic hash functions have many information-security applications, notably in
digital signatures, message authentication codes (MACs), and other forms of authentication. They can also be used as ordinary hash functions, to index data in hash tables, for fingerprinting, to detect duplicate data or uniquely identify files, and as checksums
to detect accidental data corruption. Indeed, in information-security contexts, cryptographic hash values are sometimes called (digital) fingerprints, checksums, or just hash values, even though all these terms stand for more general functions with rather different
properties and purposes.

## Objectives

This is the first ft_ssl project on the path of Encryption and Security. 

The aim is to recode some security technologies that everybody has already been using, from scratch.

It requires to plan out the structure of the executable before begining, because it will build directly onto it in later security projects. It is of vital importance that functions are modular, code is easy to re-use and adding onto the executable doesn’t require rewriting the program.

This project will focus specifically on cryptographic hashing algorithms to solidify understanding of bitwise operations, integer overflow, and one-way functions.

A subplot to this project is to emphasize writing clean code that can be efficiently extended.

## Skills

- Security 
- Rigor 
- Algorithms & AI 
- Unix  
