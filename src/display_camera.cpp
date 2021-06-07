#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <ros/ros.h>
#include <sensor_msgs/image_encodings.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "pub_cam_node");
    ros::NodeHandle nh;

    cv::VideoCapture capture(4); //0 is to read the camera, "video.format" is to read the local video
    if (!capture.isOpened()) {
        ROS_ERROR_STREAM("Failed to open video device\n");
        ros::shutdown();
    }

    //image_transport is responsible for subscription and publishing
    image_transport::ImageTransport it(nh);
    image_transport::Publisher pub_image = it.advertise("camera", 1);

    cv::Mat image;//Mat is the image class defined in OpenCV

    while (ros::ok()) {
        capture >> image; //load

        if (image.empty()) {
            ROS_ERROR_STREAM("Failed to capture image!");
            ros::shutdown();
        }
        // Convert image from cv::Mat type to sensor_msgs/Image type and publish
        pub_image.publish(cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg());// Convert image from sensor_msgs/Image type to cv::Mat type
        /*
                 Cv_bridge can selectively convert color and depth information. In order to use the specified feature encoding, there is a centralized coding form:

                 Mono8: CV_8UC1, grayscale image
                 Mono16: CV_16UC1, 16-bit grayscale image
                 Bgr8: CV_8UC3 with color information and the order of colors is BGR order
                 Rgb8: CV_8UC3 with color information and the order of colors is RGB order
                 Bgra8: CV_8UC4, BGR color image with alpha channel
                 Rgba8: CV_8UC4, CV, RGB color image with alpha channel
        */
        cv::imshow("camera", image);
        char c=(char)cv::waitKey(25);
    	if(c==27) break;
    }
    // When everything done, release the video capture object
    capture.release();
 
    // Closes all the frames
    cv::destroyAllWindows();
    ros::spin();
}

