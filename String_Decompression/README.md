This is a problem from Google Tech Dev Guide for Advanced Programming. The link to the problem is [here](https://techdevguide.withgoogle.com/paths/advanced/compress-decompression)

# The Challenge
In this exercise, we are going to decompress a compressed string.

The input is a compressed string of the format "`number[string]`" and the decompressed output form should be the string written number times. For example:

The input
```
3[abc]4[ab]c
```
Would be output as
```
abcabcabcababababc
```

## Other rules
* Number can have more than one digit. For example, `10[a]` is allowed, and just means `aaaaaaaaaa`

* One repetition can occur inside another. For example, `2[3[a]b]` decompresses into `aaabaaab`

* Characters allowed as input include digits, small English letters and brackets [ ].

* Digits are only to represent amount of repetitions.

* Letters are just letters.

* Brackets are only part of syntax of writing repeated substring.

* Input is always valid, so no need to check its validity.
