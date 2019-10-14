#include <iostream>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/keypoints/sift_keypoint.h>

using namespace std;

string write_pcd(string file_name) {
	cout << "Create a random point cloud object..." << endl;
	pcl::PointCloud<pcl::PointXYZ> cloud;
	// fill in cloud data
	cloud.width = 50;
	cloud.height = 1;
	cloud.is_dense = false;
	cloud.points.resize(cloud.width * cloud.height);
	for (size_t i = 0; i < cloud.points.size();++i) {
		cloud.points[i].x = 1024 * rand() / (RAND_MAX + 1.0f);
		cloud.points[i].y = 1024 * rand() / (RAND_MAX + 1.0f);
		cloud.points[i].z = 1024 * rand() / (RAND_MAX + 1.0f);
	}

	pcl::io::savePCDFileASCII("first.pcd", cloud);
	return file_name;
}

pcl::PointCloud<pcl::PointXYZ>::Ptr read_pcd(string file_name){
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
	if (pcl::io::loadPCDFile<pcl::PointXYZ>(file_name, *cloud) == -1)
		return 0;
	return cloud;
}

void detect_keypoints(pcl::PointCloud<pcl::PointXYZ>::Ptr &points,
					  float minscale, int nroctaves, int nrscalesperoctave, float mincontrast,
					  pcl::PointCloud<pcl::PointWithScale>::Ptr &keypointsout) {
	pcl::SIFTKeypoint<pcl::PointXYZ, pcl::PointWithScale> sift_detect;
	sift_detect.setSearchMethod(pcl::search::KdTree<pcl::PointXYZ>::Ptr(
		new pcl::search::KdTree<pcl::PointXYZ>
	));
	sift_detect.setScales(minscale, nroctaves, nrscalesperoctave);
	sift_detect.setMinimumContrast(mincontrast);
	sift_detect.setInputCloud(points);
	sift_detect.compute(*keypointsout);
}

int main() {
	string myPCD = write_pcd("first.pcd");
	pcl::PointCloud<pcl::PointXYZ>::Ptr myCloud = read_pcd(myPCD);
	pcl::PointCloud<pcl::PointWithScale>::Ptr myOut;
	float minscale = 0.1;
	int nroctaves = 4;
	int nrscalesperoctave = 2;
	float mincontrast = 0.5;
	detect_keypoints(myCloud, minscale, nroctaves, nrscalesperoctave, mincontrast, myOut);
	return 0;
}