// 
// 
// 

#include "Block.h"

class Block {
	private:
		int x; //x cordinate
		int y; //y cordinate
		int weight; //weight of the block
		bool westWall;
		bool eastWall;
		bool northWall;
		bool southWall;

	public:
		Block() {
			x = DEFAULT_VALUE;
			y = DEFAULT_VALUE;
			weight = DEFAULT_VALUE;
			northWall = false;
			southWall = false;
			eastWall = false;
			westWall = false;
		}

		void setDefaults() {
			x = DEFAULT_VALUE;
			y = DEFAULT_VALUE;
			weight = DEFAULT_VALUE;
			northWall = southWall = eastWall = westWall = false;
		}

		void setCoordinate(int xCord, int yCord) {
			x = xCord;
			y = yCord;
		}

		int* getCordinate()
		{
			int cord[] = {x, y};
			return cord;
		}

		void setNorthWall(bool w)
		{
			northWall = w;
		}

		void setSouthWall(bool w) {
			southWall = w;
		}

		void setEastWall(bool w) {
			eastWall = w;
		}

		void setWestWall(bool w) {
			westWall = w;
		}

		//checks if this block has been mapped
		bool unMapped()
		{
			return weight == -1;
		}
};

//checks if this block has been mapped
void setDefaults()
{

}
