using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Management;
using System.IO;
namespace WMI
{
    class CWMI
    {
        private ManagementObjectSearcher query;
        private ManagementObjectCollection queryCollection;
        private System.Management.ObjectQuery oq;
        private System.Management.ConnectionOptions co;
        private System.Management.ManagementScope ms;
        private string machineName;
        private EventQuery eq_;
        private ManagementEventWatcher ew_;

        public ManagementObjectCollection QueryCollection
        {
            get {return queryCollection ;}
            set { queryCollection = value; }
        }
        public CWMI(string machine_name,string username,string password) 
        {
            co = new ConnectionOptions();
            machineName = machine_name; //连接的目标机的IP地址或者机器名
            co.Username = username;                  //连接需要的用户名
            co.Password = password;
            ms = new System.Management.ManagementScope("\\\\" + machineName + "\\root\\cimv2", co); 
        }
        public void ConnectToMachine(string connectString)
        {
            oq = new System.Management.ObjectQuery(connectString);
            query = new ManagementObjectSearcher(ms, oq);
        }
        public void QueryWMI()
        {
            QueryCollection = query.Get();
        }
        public bool SetupWMIEvents()
        {
            try
            {
                string strQuery2 = "SELECT * FROM __InstanceCreationEvent where TargetInstance isa 'Win32_NTLogEvent' AND SourceName='PGenerator Manager'";
                eq_ = new EventQuery(strQuery2);
                ew_ = new ManagementEventWatcher(ms, eq_);
                ew_.EventArrived += new EventArrivedEventHandler(this.ew_EventArrived);
                ew_.Start();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception of SetupWMIEvents!"+ex.ToString());
                return false;
            }

            return true;
        }
        public void ew_EventArrived(object sender, EventArrivedEventArgs e)
        {
            Console.WriteLine("Log Event arrived!\n");
            ProcessAndStoreManagementObject((ManagementBaseObject)(e.NewEvent)["TargetInstance"]);
        }
        private bool ProcessAndStoreManagementObject(ManagementBaseObject m)
        {
            bool ret = false;
            string _source = "";
            byte[] _data = null;
            DateTime _datetime = DateTime.UtcNow;
            string _description = "";
            string _host = "";
            int _id = 0;

            FileInfo finfo = new FileInfo(@"C:\record2.txt");

            StreamWriter sw = finfo.AppendText();

            try { _source = m["SourceName"].ToString(); }
            catch (Exception) { _source = "unknown"; }
            sw.WriteLine(_source);
            
            try { _description = m["Message"].ToString(); }
            catch (Exception) { _description = ""; }
            sw.WriteLine(_description);
            sw.WriteLine("--------------------------------------------------------------");
            return ret;
        }
    }
}
