#include <cereal/types/unordered_map.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/archives/binary.hpp>
#include <cereal/archives/json.hpp>
#include <fstream>
    
struct MyRecord
{
  uint8_t x, y;
  float z;
  
  template <class Archive>
  void serialize( Archive & ar )
  {
    ar( x, y, z );
  }
};
    
struct SomeData
{
  int32_t id;
  std::shared_ptr<std::unordered_map<uint32_t, MyRecord>> data;
  
  template <class Archive>
  void save( Archive & ar ) const
  {
    ar( CEREAL_NVP(data) );
  }
      
  template <class Archive>
  void load( Archive & ar )
  {
    static int32_t idGen = 0;
    id = idGen++;
    ar(CEREAL_NVP(data));
  }
};

int main()
{
  std::ofstream os("out.cereal", std::ios::out);
  cereal::JSONOutputArchive archive( os );

  SomeData myData;
  archive.setNextName("theNextItemNameIfNotExistButYouWantDefineIt");
  archive( myData );

  return 0;
}
