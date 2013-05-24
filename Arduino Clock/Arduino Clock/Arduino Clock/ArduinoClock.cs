using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.Threading;

namespace Arduino_Clock {
    static class ArduinoClock {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main() {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());

           // ArduinoControllerMain arduino = new ArduinoControllerMain();
            
            SerialPort _Port = new SerialPort("COM7", 9600);

            _Port.Open();
           
            while (true) {
                string currentTime = DateTime.Now.ToString();
                byte[] buffer = new byte[8];
                buffer[0] = Convert.ToByte(currentTime[0]);
                buffer[1] = Convert.ToByte(currentTime[1]);

                buffer[2] = Convert.ToByte(currentTime[3]);
                buffer[3] = Convert.ToByte(currentTime[4]);

                buffer[4] = Convert.ToByte(currentTime[6]);
                buffer[5] = Convert.ToByte(currentTime[7]);

                buffer[6] = Convert.ToByte(currentTime[9]);
                buffer[7] = Convert.ToByte(currentTime[10]);

                _Port.Write(buffer, 0, 8);
                Thread.Sleep(2000);
            }
        }
    }
}