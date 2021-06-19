#!/usr/bin/env python

import cv2 as cv
import numpy
import rospy
import Tkinter
from PIL import Image, ImageTk
from sensor_msgs.msg import CompressedImage
from std_msgs.msg import String

state_info = "NONE"
ori = numpy.zeros([630, 840, 3], dtype = numpy.uint8)

def nothing(num):
    pass

def add_label(frame, title, value, row):
    label_title = Tkinter.Label(frame, text=title, fg='black', font=("Helvetica", 20, 'bold'))
    label_title.grid(row=row, column=1, pady=(15, 0), padx=(10, 0))
    label_value = Tkinter.Label(frame, text=value, fg='black', font=("Helvetica", 20, 'bold'))
    label_value.grid(row=row + 1, column=1, pady=(0, 15), padx=(10, 0))
    return label_value

def info_callback(msg):
    global state_info
    state_info = msg.data

def image_callback(img):
    global ori
    ori_cv = numpy.fromstring(img.data, numpy.uint8)
    ori_cv = cv.imdecode(ori_cv, cv.IMREAD_COLOR)
    ori = ori_cv

if __name__ == '__main__':
    # Initialize gcs node
    rospy.init_node('gcs', anonymous=True)

    # Set Subscriber nodes
    info_subscriber = rospy.Subscriber("/benam/state_info",String,info_callback)
    img_subscriber = rospy.Subscriber("/benam/image_robot/compressed", CompressedImage, image_callback)

    # Init master/root
    master = Tkinter.Tk()
    master.title("Ground Control Station")
    master_width = master.winfo_screenwidth()
    master_height = master.winfo_screenheight()
    master.geometry(str(master_width) + "x" + str(master_height))

    top_frame = Tkinter.Frame(master, width=450, height=50, pady=3)
    center = Tkinter.Frame(master, width=50, height=40, padx=3, pady=3)

    master.grid_rowconfigure(1, weight=1)
    master.grid_columnconfigure(0, weight=1)

    top_frame.grid(row=0, sticky="ew", padx=100, pady=(10, 0))
    center.grid(row=1, sticky="nsew")

    pwm_label = Tkinter.Label(top_frame, text="ARM ROBOT CAR by Hansel Matthew", font=('Aerial 22 bold'))
    pwm_label.grid(row=0, column=2)

    center.grid_rowconfigure(0, weight=1)
    center.grid_columnconfigure(1, weight=1)

    ctr_mid = Tkinter.Frame(center, width=150, height=190, padx=3, pady=3)
    ori_label = Tkinter.Label(center, image=None)
    ori_label.grid(column=1, pady=5)
    
    ctr_left = Tkinter.Frame(center, width=100, height=190)
    ctr_left.grid(row=0, column=0, sticky="ns", padx=(100, 0), pady=(100, 0))
    ctr_mid.grid(row=0, column=1, sticky="nsew")


    # INFORMATION FRAME
    pwm_label         = add_label(ctr_left, "STATE INFORMATION", state_info, 1)
    ctr_left.grid(row=0, column=0)

    master.update()

    while not rospy.is_shutdown():
        if ori is not None:
            image_hsv = cv.cvtColor(ori, cv.COLOR_BGR2HSV)
            b, g, r = cv.split(ori)
            ori_img_array = cv.merge((r, g, b))
            ori_img = Image.fromarray(ori_img_array)
            ori_img_tk = ImageTk.PhotoImage(image=ori_img)
            ori_label.config(image=ori_img_tk)

        pwm_label.config(text= state_info)
        
        master.update()