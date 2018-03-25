/*
 * SimpleUrlProvider.cpp
 *
 *  Created on: Mar 24, 2018
 *      Author: deth
 */

#include "SimpleUrlProvider.h"

SimpleUrlProvider::SimpleUrlProvider()
{
}

SimpleUrlProvider::~SimpleUrlProvider()
{
}

std::vector<UrlDescriptor> SimpleUrlProvider::get_url_pack()
{
  return
    {
        { "www.ebay.com", "/itm/M5-Wireless-WIFI-Audiocast-Airplay-DLNA-Music-Box-Streaming-Receiver-Player-N8T1/263384863504?epid=2075483707&hash=item3d52f61310:g:m4MAAOSw~HBaMDl2"},
		{ "www.ebay.com", "/itm/Raspberry-Pi-3-Model-B-Quad-Core-1-2GHz-64bit-CPU-1GB-RAM-WiFi-Bluetooth-4-1/141136387726?epid=1665704670&hash=item20dc625e8e:g:WkMAAOSwBnVW-foz"},
        { "www.amazon.com", "/dp/B01DFKC2SO"},
        { "www.amazon.com", "/gp/product/B0781Z7Y3S/ref=s9u_bmx_e_gw_i1?ie=UTF8&fpl=fresh&pd_rd_i=B0781Z7Y3S&pd_rd_r=2579eeff-3068-11e8-ba50-2f42e5cb9555&pd_rd_w=MKSG5&pd_rd_wg=SfA7v&pf_rd_m=ATVPDKIKX0DER&pf_rd_s=&pf_rd_r=YSD1AS7AFN5BS563EN64&pf_rd_t=36701&pf_rd_p=1dd2ffc3-992f-4bde-81b0-de270e0ead5a&pf_rd_i=desktop"}
    };
}
