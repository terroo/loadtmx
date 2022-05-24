#ifndef LOADTMX_H
#define LOADTMX_H
#include <tinyxml2.h>
#include <vector>
#include <iostream>

class LoadTmx {
  public:
    static const std::vector<std::vector<int>> tilemap(const char *file_tmx){
      FILE * tmx;
      if((tmx = fopen(file_tmx, "r")) == NULL){
        std::cerr << "Could not open file.\n";
        exit(1);
      }

      int row{};
      tinyxml2::XMLDocument doc;
      doc.LoadFile(tmx);

      tinyxml2::XMLElement * p_root_element = doc.RootElement();
      tinyxml2::XMLElement * p_layer = p_root_element->FirstChildElement("layer");
      tinyxml2::XMLElement * p_data = p_layer->FirstChildElement("data");

      std::size_t height = std::stoi(p_layer->Attribute("height")) + 1;
      
      std::string mapa = p_data->GetText(), value{};
      std::vector<std::vector<int>> tiles(height);
      
      for(std::size_t i{}; i < mapa.length(); ++i) {
        if(mapa[i] == ',') {
          tiles[row].push_back(std::stoi(value));
          value.clear();
        }else if(mapa[i] == '\n') {
          value.clear();
          tiles.push_back({});
          ++row;
          if(tiles.size() > height){
            tiles.pop_back();
          }
        }else if(mapa[i] >= '0' && mapa[i] <= '9'){
          value += mapa[i];
        }
      }
      tiles.erase(tiles.begin());
      fclose(tmx);
      return tiles;
    }
};
#endif
