// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*! 
 * @file SensorCombinedPubSubMain.cpp
 * This file acts as a main entry point to the application.
 *
 * This file was generated by the tool fastcdrgen.
 */


#include <string>

#include "SensorCombinedPublisher.h"
#include "SensorCombinedSubscriber.h"


#include <fastrtps/Domain.h>


using namespace eprosima;
using namespace eprosima::fastrtps;

const std::string DEFAULT_UART = "/dev/ttyACM0";

int main(int argc, char** argv)
{
	cout << "Starting " << endl;
	int type = 1;
	if (argc > 1)
	{
		if (strcmp(argv[1], "publisher") == 0)
		{
			type = 1;
		}
		else if (strcmp(argv[1], "subscriber") == 0)
		{
			type = 2;
		}
	}
	else
	{
		cout << "publisher OR subscriber argument needed" << endl;
		return 0;
	}
	

    std::string uart = DEFAULT_UART;
    if (argc > 2)
    {
        uart = argv[2];
    }

	// Register the type being used
	
	
	switch(type)
	{
		case 1:
		{
			SensorCombinedPublisher mypub;
			if (mypub.init(uart))
			{
				mypub.run();
			}
			break;
		}
		case 2:
		{
			SensorCombinedSubscriber mysub;
			if (mysub.init())
			{
				mysub.run();
			}
			break;
		}
	}
	
	return 0;
}
