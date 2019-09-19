#pragma once

namespace cg {
	struct ImageBuffer;
}

struct ImageUtilsExt {
    static void savePNG(cg::ImageBuffer const&, std::ostream&);
};

namespace mce {
	struct Image {
		Image(std::vector<unsigned char, std::allocator<unsigned char> >&&);

		void setRawImage(std::vector<unsigned char, std::allocator<unsigned char> >&&);

		void copyRawImage(std::vector<unsigned char, std::allocator<unsigned char> > const&);

		void resizeImageBytesToFitImageDescription();

		bool isEmpty() const;
	};

	struct ImageUtils {
		// Returns size, I think?
		static short uncompress(Image &);
	};
}

namespace cg {
	struct ImageDescription {
		unsigned int getArraySize() const;

		unsigned int getStorageSize() const;

		unsigned int getSubimageSize();
	};

	struct ImageBuffer {
		ImageBuffer(mce::Image &&);

		ImageBuffer(mce::Image const&);

		void allocateStorage(cg::ImageDescription const&);

		ImageDescription getImageDescription() const;

		bool isEmpty() const;

		bool isValid() const;

		unsigned int getStorageSize() const;

		unsigned char get(unsigned int);

		/*std::vector<unsigned char, std::allocator<unsigned char>> &*/unsigned char *data() const;
	};


}
