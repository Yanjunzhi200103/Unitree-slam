/*****************************************************************
 Copyright (c) 2020, Unitree Robotics.Co.Ltd. All rights reserved.
******************************************************************/

#ifndef _CONVERT_H_
#define _CONVERT_H_

#include "unitree_legged_sdk/unitree_legged_sdk.h"
#include <slam_planner/LowCmd.h>
#include <slam_planner/LowState.h>
#include <slam_planner/HighCmd.h>
#include <slam_planner/HighState.h>
#include <slam_planner/MotorCmd.h>
#include <slam_planner/MotorState.h>
#include <slam_planner/IMU.h>


slam_planner::IMU ToRos(UNITREE_LEGGED_SDK::IMU& lcm)
{
    slam_planner::IMU ros;
    ros.quaternion[0] = lcm.quaternion[0];
    ros.quaternion[1] = lcm.quaternion[1];
    ros.quaternion[2] = lcm.quaternion[2];
    ros.quaternion[3] = lcm.quaternion[3];
    ros.gyroscope[0] = lcm.gyroscope[0];
    ros.gyroscope[1] = lcm.gyroscope[1];
    ros.gyroscope[2] = lcm.gyroscope[2];
    ros.accelerometer[0] = lcm.accelerometer[0];
    ros.accelerometer[1] = lcm.accelerometer[1];
    ros.accelerometer[2] = lcm.accelerometer[2];
    ros.rpy[0] = lcm.rpy[0];
    ros.rpy[1] = lcm.rpy[1];
    ros.rpy[2] = lcm.rpy[2];
    ros.temperature = lcm.temperature;
    return ros;
}

slam_planner::MotorState ToRos(UNITREE_LEGGED_SDK::MotorState& lcm)
{
    slam_planner::MotorState ros;
    ros.mode = lcm.mode;
    ros.q = lcm.q;
    ros.dq = lcm.dq;
    ros.ddq = lcm.ddq;
    ros.tauEst = lcm.tauEst;
    ros.q_raw = lcm.q_raw;
    ros.dq_raw = lcm.dq_raw;
    ros.ddq_raw = lcm.ddq_raw;
    ros.temperature = lcm.temperature;
    ros.reserve[0] = lcm.reserve[0];
    ros.reserve[1] = lcm.reserve[1];
    return ros;
}

UNITREE_LEGGED_SDK::MotorCmd ToLcm(slam_planner::MotorCmd& ros)
{
    UNITREE_LEGGED_SDK::MotorCmd lcm;
    lcm.mode = ros.mode;
    lcm.q = ros.q;
    lcm.dq = ros.dq;
    lcm.tau = ros.tau;
    lcm.Kp = ros.Kp;
    lcm.Kd = ros.Kd;
    lcm.reserve[0] = ros.reserve[0];
    lcm.reserve[1] = ros.reserve[1];
    lcm.reserve[2] = ros.reserve[2];
    return lcm;
}

slam_planner::LowState ToRos(UNITREE_LEGGED_SDK::LowState& lcm)
{
    slam_planner::LowState ros;
    ros.levelFlag = lcm.levelFlag;
    ros.commVersion = lcm.commVersion;
    ros.robotID = lcm.robotID;
    ros.SN = lcm.SN;
    ros.bandWidth = lcm.bandWidth;
    ros.imu = ToRos(lcm.imu);
    for(int i = 0; i<20; i++){
        ros.motorState[i] = ToRos(lcm.motorState[i]);
    }
    for(int i = 0; i<4; i++){
        ros.footForce[i] = lcm.footForce[i];
        ros.footForceEst[i] = lcm.footForceEst[i];
    }
    ros.tick = lcm.tick;
    for(int i = 0; i<40; i++){
        ros.wirelessRemote[i] = lcm.wirelessRemote[i];
    }
    ros.reserve = lcm.reserve;
    ros.crc = lcm.crc;
    return ros;
}

UNITREE_LEGGED_SDK::LowCmd ToLcm(slam_planner::LowCmd& ros)
{
    UNITREE_LEGGED_SDK::LowCmd lcm;
    lcm.levelFlag = ros.levelFlag;
    lcm.commVersion = ros.commVersion;
    lcm.robotID = ros.robotID;
    lcm.SN = ros.SN;
    lcm.bandWidth = ros.bandWidth;
    for(int i = 0; i<20; i++){
        lcm.motorCmd[i] = ToLcm(ros.motorCmd[i]);
    }
    for(int i = 0; i<4; i++){
        lcm.led[i].r = ros.led[i].r;
        lcm.led[i].g = ros.led[i].g;
        lcm.led[i].b = ros.led[i].b;
    }
    for(int i = 0; i<40; i++){
        lcm.wirelessRemote[i] = ros.wirelessRemote[i];
    }
    lcm.reserve = ros.reserve;
    lcm.crc = ros.crc;
    return lcm;
}

slam_planner::HighState ToRos(UNITREE_LEGGED_SDK::HighState& lcm)
{
    slam_planner::HighState ros;
    ros.levelFlag = lcm.levelFlag;
    ros.commVersion = lcm.commVersion;
    ros.robotID = lcm.robotID;
    ros.SN = lcm.SN;
    ros.bandWidth = lcm.bandWidth;
    ros.mode = lcm.mode;
    ros.imu = ToRos(lcm.imu);
    ros.forwardSpeed = lcm.velocity[0];
    ros.sideSpeed = lcm.velocity[1];
    ros.rotateSpeed = lcm.yawSpeed;
    ros.bodyHeight = lcm.bodyHeight;
    //ros.forwardPosition = lcm.forwardPosition;
    //ros.sidePosition = lcm.sidePosition;
    for(int i = 0; i<4; i++){
        ros.footPosition2Body[i].x = lcm.footPosition2Body[i].x;
        ros.footPosition2Body[i].y = lcm.footPosition2Body[i].y;
        ros.footPosition2Body[i].z = lcm.footPosition2Body[i].z;
        ros.footSpeed2Body[i].x = lcm.footSpeed2Body[i].x;
        ros.footSpeed2Body[i].y = lcm.footSpeed2Body[i].y;
        ros.footSpeed2Body[i].z = lcm.footSpeed2Body[i].z;
        ros.footForce[i] = lcm.footForce[i];
        ros.footForceEst[i] = lcm.footForceEst[i];
    }
    for(int i = 0; i<40; i++){
        ros.wirelessRemote[i] = lcm.wirelessRemote[i];
    }
    ros.reserve = lcm.reserve;
    ros.crc = lcm.crc;
    return ros;
}

UNITREE_LEGGED_SDK::HighCmd ToLcm(slam_planner::HighCmd& ros)
{
    UNITREE_LEGGED_SDK::HighCmd lcm;
    lcm.levelFlag = ros.levelFlag;
    lcm.commVersion = ros.commVersion;
    lcm.robotID = ros.robotID;
    lcm.SN = ros.SN;
    lcm.bandWidth = ros.bandWidth;
    lcm.mode = ros.mode;
    lcm.velocity[0] = ros.forwardSpeed;
    lcm.velocity[1] = ros.sideSpeed;
    lcm.yawSpeed = ros.rotateSpeed;
    lcm.bodyHeight = ros.bodyHeight;
    lcm.footRaiseHeight = ros.footRaiseHeight;
    lcm.euler[2] = ros.yaw;
    lcm.euler[1] = ros.pitch;
    lcm.euler[0] = ros.roll;
    for(int i = 0; i<4; i++){
        lcm.led[i].r = ros.led[i].r;
        lcm.led[i].g = ros.led[i].g;
        lcm.led[i].b = ros.led[i].b;
    }
    for(int i = 0; i<40; i++){
        lcm.wirelessRemote[i] = ros.wirelessRemote[i];
    }
    lcm.reserve = ros.reserve;
    lcm.crc = ros.crc;
    return lcm;
}


#endif
