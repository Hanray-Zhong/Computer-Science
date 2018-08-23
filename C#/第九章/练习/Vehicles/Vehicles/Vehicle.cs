using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Vehicles
{
    public class Vehicle
    {
    }

    public interface IPassengerCarrier
    { }
    public interface IHeavyLoadCarrier
    { }

    public class train : Vehicle
    { }
    public class PassengerTrain : train,IPassengerCarrier
    { }
    public class FreightTrain : train,IHeavyLoadCarrier
    { }
    public class _424DoubleBogey : train
    { }

    public class Car : Vehicle
    { }
    public class Compact : Car,IPassengerCarrier
    { }
    public class SUV : Car,IPassengerCarrier
    { }
    public class Pickup : Car,IHeavyLoadCarrier
    { }


}
