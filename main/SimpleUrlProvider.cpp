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
        { "www.amazon.com", "/dp/B01DFKC2SO"}
    };
}
