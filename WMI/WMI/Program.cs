using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Management;
using System.IO;
namespace WMI
{
    class Program
    {

        static void Main(string[] args)
        {
             Console.WriteLine("Get Information start!");
         /*    ManagementObjectSearcher query;      
             ManagementObjectCollection queryCollection;
             System.Management.ObjectQuery oq;
             System.Management.ConnectionOptions co = new ConnectionOptions();
            
             string machineName = "10.86.17.128"; //连接的目标机的IP地址或者机器名
             co.Username = "Administrator";                  //连接需要的用户名
             co.Password = "j";           //连接需要的密码
             string connectString = "SELECT * FROM Win32_NTLogEvent where LogFile = 'PIsys' AND SourceName='Key Server Manager'";   //查询字符串
 
             System.Management.ManagementScope ms = new System.Management.ManagementScope("\\\\" + machineName + "\\root\\cimv2", co); 
             oq = new System.Management.ObjectQuery( connectString );
             query = new ManagementObjectSearcher( ms, oq );
             queryCollection = query.Get();*/
            // FileStream fs = new FileStream(@"D:\record.txt", FileMode.Create, FileAccess.Write);
             CWMI wmi = new CWMI("10.86.17.129", "KMSAdmin", "j");
             //CWMI wmi = new CWMI("localhost", "", "");
             string connectString = "SELECT * FROM Win32_NTLogEvent where LogFile = 'PIsys' AND SourceName='PGenerator Manager'";   //查询字符串
             wmi.ConnectToMachine(connectString);
            // wmi.QueryWMI();
             wmi.SetupWMIEvents();
             /*FileInfo finfo = new FileInfo(@"D:\record1.txt");
            
             StreamWriter sw = finfo.AppendText();
             foreach ( ManagementObject mo in wmi.QueryCollection)
             {
                // string hardwareID     = mo["HardwareID"]); //直接根据属性名得到属性的值

                //遍历所有属性，得到所有属性的值
                PropertyDataCollection searcherProperties = mo.Properties;
                foreach (PropertyData sp in searcherProperties)
                {
                    if (sp.Name == "SourceName" || sp.Name == "Message" || sp.Name == "TimeGenerated" || sp.Name == "TimeWritten" || sp.Name == "EventCode")
                    {
                        string record = String.Format("Name = {0, -20}, Value = {1, -20}\n", sp.Name, sp.Value);
                        sw.WriteLine(record);
                    }
                }
                sw.WriteLine("--------------------------------------------------------------------------");
                
            }*/
             Console.WriteLine("Get Information Sucessed!");
             char end = (char)Console.Read();
        }
    }
}
