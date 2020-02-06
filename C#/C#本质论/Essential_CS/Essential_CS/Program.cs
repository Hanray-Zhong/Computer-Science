using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;
using Essential_CS.Chapter7;
using Essential_CS.Chapter14;


namespace Essential_CS
{
    // chapter 14
    class Program {
        static void Main(string[] args) {
            Thermostat thermostat = new Thermostat();
            Cooler cooler = new Cooler(60);
            Heater heater = new Heater(80);

            string temperature;

            // 注册订阅者
            thermostat.OnTemperatureChange += cooler.OnTemperatureChanged;
            thermostat.OnTemperatureChange += heater.OnTemperatureChanged;

            Write("Enter temperature : ");
            temperature = ReadLine();
            thermostat.CurrentTemperature = int.Parse(temperature);
        }
    }



    /*class Program {
        static void Main(string[] args) {

        }
    }*/
}
