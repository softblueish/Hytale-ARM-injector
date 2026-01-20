#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return 1;
    }

    std::string username = getenv("USERNAME");
    std::string command = "C:\\Users\\" + username + "\\AppData\\Roaming\\Hytale\\install\\release\\package\\jre-native\\latest\\bin\\java.exe";
    for (int i = 1; i < argc; ++i) {
        command += " ";
        if(command.substr(0, 2) == "C:") {
            command += "\"";
            command += argv[i];
            command += "\"";
        } else {
            command += argv[i];
        }
    }

    if(command.find("HytaleServer.jar") != std::string::npos) {
        size_t pos = command.find("jre-native");
        if (pos != std::string::npos) {
            command.replace(pos, std::string("jre-native").length(), "jre-non-native");
        }
    }

    system(command.c_str());
    return 0;
}