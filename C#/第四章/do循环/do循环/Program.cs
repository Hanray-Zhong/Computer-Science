using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using static System.Convert;

namespace do循环
{
    class Program
    {
        static void Main(string[] args)
        {
            double balance, interestRate, targetBalance;
            WriteLine("What is your current balance?");
            balance = ToDouble(ReadLine());
            WriteLine("What is your current annual interest rate (in %)?");
            interestRate = 1 + ToDouble(ReadLine())/100.0;
            WriteLine("What balance would you like to have?");
            targetBalance = ToDouble(ReadLine());
            int totalyeaers = 0;
            do
            {
                balance *= interestRate;
                ++totalyeaers;
            }
            while (balance < targetBalance);
            WriteLine($"In {totalyeaers} year{(totalyeaers == 1 ? " " : "s")} " +
                $"you will have a balance of {balance}.");
            ReadKey();
        }
    }
}
