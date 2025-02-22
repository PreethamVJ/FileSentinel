#ifndef CONFIG_HPP
#define CONFIG_HPP
#include <filesystem>
#include <vector>
#include <string>
#include <yaml-cpp/yaml.h>

using namespace std;

using namespace std::filesystem; 

//enumeration for logging levels
enum LogLevel {
  INFO, //normal log level
  WARN, //log only warning
  ERROR, //log only error
  DEBUG, //log only debug info
};

//enumeration for supported hashing algorithms
enum Algorithm {
  MD5, //use MD5 algo for hashing
  SHA256, //use SHA256 algo for hashing
  NONE, //no hashing
};

//configuration class for managing settings from a YAML file
class Config {
private:
  YAML::Node yaml; //YAML object
  vector<path> paths; //vector of paths to check
  int interval; //time interval
  bool notification_enabled; //is notification enabled
  path log_file; //path to log file
  LogLevel log_level; //log level
  Algorithm algorithm; //algo used for hashing
 
public:
  Config(); //constructor
 
  void parse(const path&); //parse given yaml

  //getters for configuration parameters
  vector<path> get_paths();
  int get_interval();
  bool get_noti_enabled();
  string get_log_file();
  string get_on_change_command();
  int get_max_threads();
  LogLevel get_log_level();
  Algorithm get_algorithm();

  //setters for configuration parameters
  void update_interval(int);
  void update_noti_enabled(bool);
  void update_log_file(string);
  void update_on_change_command(string);
  void update_max_threads(int);
  void update_log_level(LogLevel);
  void update_algorithm(Algorithm);

  ~Config(); //destructor
  
};

#endif 

