echo "Asking for sudo permissions for apt and editing system files."
sudo apt update
sudo apt install -y hostapd
sudo systemctl unmask hostapd
sudo systemctl enable hostapd
sudo apt install dnsmasq
sudo DEBIAN_FRONTEND=noninteractive apt install -y netfilter-persistent iptables-persistent
echo -e "interface wlan0\nstatic ip_address=192.168.4.1/24\nnohook wpa_supplicant" | sudo tee -a /etc/dhcpcd.conf
echo -e "# https://www.raspberrypi.org/documentation/configuration/wireless/access-point-routed.md\n# Enable IPv4 routing\nnet.ipv4.ip_forward=1" | sudo tee -a /etc/sysctl.d/routed-ap.conf
sudo iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE
sudo netfilter-persistent save
sudo mv /etc/dnsmasq.conf /etc/dnsmasq.conf.orig
sudo echo -e "interface=wlan0 # Listening interface\ndhcp-range=192.168.4.2,192.168.4.20,255.255.255.0,24h # Pool of IP addresses served via DHCP\ndomain=wlan     # Local wireless DNS domain\naddress=/proto.gen/192.168.4.1 # Alias for this router" | sudo tee /etc/dnsmasq.conf
sudo rfkill unblock wlan
while [ ${#countrycode} != 2 ]
do
echo "Please enter your wifi country code to enable your WiFi spectrum (see https://preview.tinyurl.com/WiFiCodes): " 
read countrycode
countrycode=${countrycode^^}
done
while [ ${#SSID} -lt 2 ] || [ ${#SSID} -gt 32 ]
do
echo "Please enter your desired network name (2-32 characters): " 
read SSID
done
while [ ${#netPass} -lt 8 ] || [ ${#netPass} -gt 63 ]
do
echo "Please enter a password for the network (8-63 characters): " 
read netPass
done
echo -e "country_code=$countrycode\ninterface=wlan0\nssid=$SSID\nhw_mode=g\nchannel=7\nmacaddr_acl=0\nauth_algs=1\nignore_broadcast_ssid=0\nwpa=2\nwpa_passphrase=$netPass\nwpa_key_mgmt=WPA-PSK\nwpa_pairwise=TKIP\nrsn_pairwise=CCMP" | sudo tee -a /etc/hostapd/hostapd.conf
echo "Your RasPi will reboot in 10 seconds to enable this configuration. To cancel reboot press CTRL+C"
echo "After reboot you can access this device at 192.168.4.1, or at proto.gen on some devices"
sleep 10
sudo systemctl reboot