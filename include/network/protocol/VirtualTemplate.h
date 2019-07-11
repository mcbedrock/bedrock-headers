// The pure virtual function "implementations" to make the compiler happy. Include this inside a subpackets class.

virtual void read(ReadOnlyBinaryStream &);

virtual int getId() const;

virtual void write(BinaryStream &) const;

virtual std::string getName() const;