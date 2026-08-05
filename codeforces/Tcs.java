/*Question 1: Circular Prime Anagram Groups (Hard)
Problem

You are given N words consisting only of lowercase letters.

A word is considered special if:

The frequency of its letters can be rearranged to form a prime number.
Example:
"abb" → frequencies = {a:1,b:2} → "12" or "21"
12 is not prime, 21 is not prime → Not special
"aab" → frequencies {a:2,b:1} → 21 or 12 → Not special
"abc" → frequencies {1,1,1} → 111 → Not prime
Every cyclic rotation of the word must also be an anagram of some word present in the input.

Print all special words sorted lexicographically. */
import jav.util.*;

class Tcs
{
	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();

		for(int i = 0; i < n; i++){

			String s = s.nextInt();
