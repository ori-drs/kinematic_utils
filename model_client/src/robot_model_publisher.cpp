// file: robot_model_publisher.cpp
// Broadcasts an URDF repeatedly

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <time.h>

#include "urdf/model.h"
#include <lcm/lcm-cpp.hpp>
#include "lcmtypes/bot_core/robot_urdf_t.hpp"

#include <model_client/model_client.hpp>


using namespace std;

int main(int argc, char ** argv)
{

  if (argc != 2) {
    fprintf(stderr, "Correct Usage: %s <filename.urdf>\n", argv[0]);
    exit(1);
  }

  string urdf_file = std::string(argv[1]);//  "path_to_your.urdf";
  std::cout << "urdf_file: " << urdf_file << "\n";

  ModelClient* model_client;
  model_client =  new ModelClient(urdf_file);
  
  lcm::LCM lcm("");
  if(!lcm.good())
      return 1;
    
  bot_core::robot_urdf_t message;
  message.robot_name = model_client->getRobotName();
  message.urdf_xml_string = model_client->getURDFString();
  message.left_hand = model_client->getLeftHand(); 
  message.right_hand = model_client->getRightHand();
  
  std::cout << "Broadcasting urdf of robot [" << model_client->getRobotName() << "] as a string at 1Hz\n";
  struct timeval tv;
  while(true){
    gettimeofday (&tv, NULL);
    message.utime = (int64_t) tv.tv_sec * 1000000 + tv.tv_usec; // TODO: replace with bot_timestamp_now() from bot_core
    lcm.publish("ROBOT_MODEL", &message);
    usleep(2000000); // used to publish at 1Hz, now publish at 0.5Hz
  }
    
  return 0;
}
