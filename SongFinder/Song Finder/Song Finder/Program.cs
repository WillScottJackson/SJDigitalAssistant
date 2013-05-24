using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WMPLib;

namespace AxWMPLib {
    class Program {
        static void Main(string[] args) {
           WindowsMediaPlayer Player = new WindowsMediaPlayer();
           IWMPPlaylist list = Player.mediaCollection.getAll();

            for (int cnt = 0; cnt < list.count; cnt++)
            {
                
                Player.currentPlaylist.insertItem(cnt, list.Item[cnt]);
                Player.controls.play();
                System.Console.WriteLine(list.Item[cnt].name);
            }

            System.Console.Read();
            

        }
    }
}
