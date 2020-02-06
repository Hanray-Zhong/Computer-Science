using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace Essential_CS.Chapter7 {
    class Preson {
        public string name;
        public int age;

        public void Person(string name, int age) {
            this.name = name;
            this.age = age;
            WriteLine("name : " + name);
            WriteLine("age : " + age);
        }
        public void PrintInfo(string name, int age) {
            WriteLine("Name is {0}, {1} years old", name, age);
        }
    }
}
