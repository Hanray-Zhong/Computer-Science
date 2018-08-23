using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Vehicles;
using static System.Console;

namespace Traffic
{
    class Program
    {
        static void Main(string[] args)
        {
            AddPassenger(new Compact());
            AddPassenger(new SUV());
            AddPassenger(new PassengerTrain());
            ReadKey();
        }
        static void AddPassenger(IPassengerCarrier vehicle)
        {
            WriteLine(vehicle.ToString());
        }
    }
}
