/*
   File: main.cpp
   Description: Takes an inputed positive integer, then outputs the prime numbers up to it.
   Author: Spencer Tsao
   Email: spencet2544@student.vvc.edu
*/
#include<iostream>
#include<set>

int main()
{
  int userInput = 0;
  while (!(userInput > 0))
  {
    std::cout << "Enter a positive integer: " << std::endl;
    std::cin >> userInput;
    if (std::cin.fail() || userInput <= 0)
    {
      std::cout << "Invalid input." << std::endl;
      std::cin.clear();
    }
    else
    {
      std::set<int> primes;
      int i = 0;
      while (i < userInput)
      {
	i++;
	primes.insert(i);
      }
      i = 2;
      while (i * i <= userInput)
      {
	if (primes.count(i))
	{
 	  int temp = i + 1;
	  while (temp <= userInput)
	  {
	    if ((temp % i) == 0)
	      primes.erase(temp);
	    temp++;
	  }
	}
	i++;
      }
      std::cout << "The prime numbers up to " << userInput << " are: ";
      for (int prime : primes)
      {
	std::cout << prime << " ";
      }
      std::cout << std::endl;
    }  
  }
  return 0;
}

