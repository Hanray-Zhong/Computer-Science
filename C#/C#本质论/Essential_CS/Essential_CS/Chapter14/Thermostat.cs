using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Essential_CS.Chapter14 {
    public class Thermostat {
        // 委托类型，无返回值，接受一个float参数，用来存储订阅者列表，可以储存所有订阅者（与订阅者的方法形式一致）
        public Action<float> OnTemperatureChange { get; set; }

        // 通过CurrentTemperature属性，将温度通知给订阅者
        public float CurrentTemperature { 
            get { return _CurrentTemperature; } 
            set {
                if (value != CurrentTemperature) {
                    _CurrentTemperature = value;
                    // 向所有订阅者传递变化后的温度（检查 OnTemperatureChang 是否为 null）
                    // c# 6.0 检测是否为 null 再进行调用，未做错误处理
                    // OnTemperatureChang?.Invoke(value);

                    // 错误处理：手动遍历所有订阅者，再单独调用
                    Action<float> onTemperature = OnTemperatureChange;
                    if (onTemperature != null) {
                        List<Exception> exceptionsCollection = new List<Exception>();
                        foreach (Action<float> handler in onTemperature.GetInvocationList()) {
                            try {
                                handler.Invoke(value);
                            }
                            catch (Exception exception) {
                                // 错误列表
                                exceptionsCollection.Add(exception);
                            }
                        }
                        if (exceptionsCollection.Count > 0) {
                            throw new AggregateException("Error : OntemperatureChange Event Subscribers.", exceptionsCollection);
                        }
                    }
                }
            } 
        }
        private float _CurrentTemperature;
    }

    class Cooler {
        public float Temperature { get; set; }
        public Cooler(float temperature) {
            Temperature = temperature;
        }

        public void OnTemperatureChanged(float newTemperature) {
            if (newTemperature > Temperature) {
                System.Console.WriteLine("Cooler : On.");
            }
            else {
                System.Console.WriteLine("Cooler : off.");
            }
        }
    }

    class Heater {
        public float Temperature { get; set; }
        public Heater(float temperature) {
            Temperature = temperature;
        }
        public void OnTemperatureChanged(float newTemperature) {
            if (newTemperature < Temperature) {
                System.Console.WriteLine("Heater : on.");
            }
            else {
                System.Console.WriteLine("Heater : off.");
            }
        }
    }

}
