#!/usr/bin/env python

import cv2 as cv
import rospy
from sensor_msgs.msg import CompressedImage
import numpy as np

if __name__ == '__main__':
    rospy.init_node("camera")
    image_publisher = rospy.Publisher("/benam/image_robot/compressed", CompressedImage, queue_size=8)

    # Capture from camera
    cap = cv.VideoCapture(0)

    try:
        while not rospy.is_shutdown():
            # Read from camera, then convert into msgs
            _, data = cap.read()

            resized_data = cv.resize(data, (840, 630))

            msg = CompressedImage()
            msg.header.stamp = rospy.Time.now()
            msg.format = "jpeg"
            msg.data = np.array(cv.imencode('.jpg', resized_data)[1]).tostring()

            image_publisher.publish(msg) # publish image compressed
    
    except:
        cap.release()
