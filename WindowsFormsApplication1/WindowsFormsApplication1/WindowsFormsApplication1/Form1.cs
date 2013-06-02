using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.IO.Ports;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        SerialPort arduino;

        private void Form1_Load(object sender, EventArgs e)
        {
            try
            {
                arduino = new SerialPort("COM7");
                arduino.Open();
            }
            catch (IOException)
            {

            }
            catch (UnauthorizedAccessException)
            {

            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            DateTime Cur = DateTime.Now;
            List<Char> Buffer = new List<Char>();

            Buffer.Add(Convert.ToChar(Cur.Second));
            Buffer.Add(Convert.ToChar(Cur.Minute));
            Buffer.Add(Convert.ToChar(Cur.Hour));
            Buffer.Add(Convert.ToChar(Cur.Day));
            Buffer.Add(Convert.ToChar(Cur.Month));

            arduino.Write(Buffer.ToArray(), 0, Buffer.Count);
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            arduino.Close();
        }
    }
}
