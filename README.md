<div id="top"></div>

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/Reda96R/Sieve-of-Eratosthenes">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">Sieve of Eratosthenes</h3>


</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li><a href="#code-summary">Code summary</a></li>
    <li><a href="#the-algorithm">The algorithm</a></li>
    <ul>
      <li><a href="#prime-numbers">Prime numbers</a></li>
      <li><a href="#sieve-of-eratosthenes">Sieve of Eratosthenes</a></li>
      </ul>
    <li><a href="#the-emplementation">The emplementation</a></li>
    <li><a href="#note">Note</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>


  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project
Prime numbers have always been an interesting topic to dive into. but, no one has been able to find a clean and finite formula to generate them. Therefore, mathematicians have relied on algorithms and computational power to do that. Some of these algorithms can be time-consuming while others can be faster, from <strong><a href="https://en.wikipedia.org/wiki/Sieve_of_Atkin">the Sieve of Atkin</a></strong> to <strong><a href="https://en.wikipedia.org/wiki/Sieve_of_Sundaram">the  Sieve of Sundaram</a></strong>. but of one of the most efficient ways to find all primes smaller than `n` when `n` is smaller than `10 million` or so, is <strong>the Sieve of Eratosthenes</strong>.so I tried to make a C code that can find primes using the Eratosthene’s method.
### Built With
* [C](https://www.iso.org/standard/74528.html)


## Code summary
 First, let's do a quick summary of what the program is going to do:
 1. the pogram should create a list of all numbers from `2`(because it's the first prime) to `n`.
 2. in this step the code should filter the numbers and find all primes.
 3. last it should print the primes found in step 2.


<!-- The algorithm-->
## The algorithm

### Prime numbers
First of all what is a prime number?<br>
in math, a prime number is a whole number greater than 1 that have only two factors `1` and `the number itself`.

### Sieve of Eratosthenes
the Sieve of Eratosthenes is one of the oldest and easiest methods for finding prime numbers up to a given number. It is based on eliminating all the multiples of a prime. To do so, it starts with `2` as the first prime number and eliminate all of its multiples `(4, 6, 8, ...)`. Then, it marks the next uneliminated number `3` as prime and crosses out all its multiples `(6, 9, 12, ...)`. It does the same for all the other numbers up to `n`, in other words A number is prime, if none of the smaller prime numbers divides it.
to get a clear image, let's take for example `n = 18` So we need to print all prime numbers smaller than or equal to `18`.
<br><br>
let's start with `2`(since it is the smallest prime number), next we're going to eliminate all its multiples `4,6,8,10,12,14,16,18`, Then we find the next number that hasn't been eliminated, in this case it is `3`. Which means `3` is prime, and we eliminate all multiples of `3`. The next uneliminated number is `5`, which is the next prime number, and we eliminate all multiples of it. And we continue this procedure until we processed all numbers in the row.
<div align="center"><a href="#"><img src="images/Explain.png" alt="Explaining" width="700"></a></div>
<br>
The idea behind it is, a number is prime, if none of the smaller prime numbers divides it. Since we iterate over the prime numbers in order, we already eliminated all numbers who are divisible by at least one of the prime numbers, as divisible. Hence if we reach a cell and it is not eliminated, then it isn't divisible by any smaller prime number and therefore has to be prime.

### Note:
As we can see, some numbers get crossed several times. In order to avoid it, for each prime `p`, we can start from `p²` to mark off its multiples. The reason is that once we get to a prime `p` in the process, all its multiples smaller than `p²` have already been crossed out. For example, let’s imagine that we get to `3`. Then, we can see that `6,12,18` have already been eleminated by `2` . As a result, we can begin with `9`.

## The emplementation: 
To emplement this algorithm in my code, I included two C libaries,
```sh
#include<stdio.h>
#include<string.h>
```
<strong><a href="https://www.tutorialspoint.com/c_standard_library/stdio_h.htm">stdio.h</a></strong> so I can use `printf`, and <strong><a href="https://www.tutorialspoint.com/c_standard_library/string_h.htm">string.h</a></strong> to use <a href="https://www.geeksforgeeks.org/memset-c-example/">`memset`</a> which is a function used to fill a block of memory with a particular value, in this case `nums[]` to be filled with `0`
```ssh
void    S_Eratosthenes(int n)
  {
    int     nums[n];
    memset (nums, 0, sizeof(int) * n);

```
next, inside a function `S_Eratosthenes` that reiceves an `int n`, I created an array `num[0..n]` and initialize all entries it as `0` using `memset`. so in the end a value in `num[]` will be `1` if it is Not a prime, else `0`.
```sh
for (int p = 2; p <= n; p++)
{

```
Then there is a <a href="https://www.programiz.com/c-programming/c-for-loop">`for loop`</a> that iterates over all numbers from `2` to `n`
```sh
if (nums[p - 1] == 0)
  {
    for (int np = p * p; np <= n; np += p)
    nums[np - 1] = 1;
  }

```
If the current number `p-1` is a prime number (in our logic it equals to `0`), then it marks all numbers that are multiples of `p-1` as `1`, starting from `np = p²` as I <a href="#note">mentioned</a> earlier
```sh
for (int p = 2; p <= n; p++)
  if(nums[p - 1] == 0)
    printf ("%d, ", p);
```
Last I created this for loop to print all primes, marked as `0`.

## Note
The biggest weakness of this algorithm is, that it "walks" along the memory multiple times, only manipulating single elements. This is not very cache friendly. And because of that, the consumed memory is a bottleneck for big `n`.
<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<!-- CONTACT -->
## Contact

Reda Rayyad - [Twitter](https://twitter.com/reda_rayyad) - [Instagram](https://www.instagram.com/reda_rayyad/) - redarayyad@yahoo.com

Project Link: [https://github.com/Reda96R/Password-Generator](https://github.com/Reda96R/Sieve-of-Eratosthenes)

<!-- ACKNOWLEDGMENTS -->
## Acknowledgments
Here you can find some of the resources that I found helpful while making this script
* [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)
* [Sieve of Eratosthenes explained](https://www.youtube.com/watch?v=klcIklsWzrY)
* [memset() in C](https://www.geeksforgeeks.org/memset-c-example/)
* [Sieve of Eratosthenes in Python](https://www.youtube.com/watch?v=hA33qcD_Quc)
* [This amazing Readme Template made by @othneildrew](https://github.com/othneildrew/Best-README-Template)

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/Reda96R/Password-Generator.svg?style=for-the-badge
[contributors-url]: https://github.com/Reda96R/Password-Generator/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/Reda96R/Password-Generator.svg?style=for-the-badge
[forks-url]: https://github.com/Reda96R/Password-Generator/network/members
[stars-shield]: https://img.shields.io/github/stars/Reda96R/Password-Generator.svg?style=for-the-badge
[stars-url]: https://github.com/Reda96R/Password-Generator/stargazers
[issues-shield]: https://img.shields.io/github/issues/Reda96R/Password-Generator.svg?style=for-the-badge
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/reda_rayyad
