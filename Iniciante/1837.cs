using System;

namespace Beecrowd
{
  class Program
  {
    static void Main(string[] args)
    {
      string input = Console.ReadLine();
      int a = int.Parse(input.Split()[0]);
      int b = int.Parse(input.Split()[1]);

      int q, r;

      q = a / b;
      r = a % b;

      if (r < 0)
      {
        if (b > 0)
        {
          q--;
          r += b;
        }
        else
        {
          q++;
          r -= b;
        }
      }

      Console.WriteLine(q + " " + r);
    }
  }
}