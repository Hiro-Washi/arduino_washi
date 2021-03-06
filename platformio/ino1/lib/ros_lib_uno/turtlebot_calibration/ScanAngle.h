#ifndef _ROS_turtlebot_calibration_ScanAngle_h
#define _ROS_turtlebot_calibration_ScanAngle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace turtlebot_calibration
{

  class ScanAngle : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _scan_angle_type;
      _scan_angle_type scan_angle;

    ScanAngle():
      header(),
      scan_angle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->scan_angle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->scan_angle));
     return offset;
    }

    virtual const char * getType() override { return "turtlebot_calibration/ScanAngle"; };
    virtual const char * getMD5() override { return "06e2c839dc5c7f5c13ac09a8b4ff0a6a"; };

  };

}
#endif
