using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace split函数
{
    class Program
    {
        static void Main(string[] args)
        {
            string myString;
            string[] myWord;
            char[] charracter = { 'a','b' };
            myString = ReadLine();
            myWord = myString.Split(charracter); //split()函数，遇到参数所含的字符时以此为界分割字符串，并将该字符删除
            foreach(string word in myWord)
            {
                WriteLine($"{ word}");
            }
            ReadKey();
        }
    }
}
