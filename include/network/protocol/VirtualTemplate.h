// The pure virtual function "implementations" to make the compiler happy. Include this inside a subpackets class.

virtual int getId() const;

virtual std::string getName() const;

virtual void write(BinaryStream &) const;

virtual void read(BinaryStream &);

virtual void handle(NetworkIdentifier const &, NetEventCallback &) const;

virtual bool disallowBatching() const;
