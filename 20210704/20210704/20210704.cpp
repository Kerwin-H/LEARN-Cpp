
	bool insert(const pair<K, V>& kv){		

	
		if (_header->_parent == nullptr){		

			
			Node* root = new Node(kv);

		
			_header->_parent = root;
			root->_parent = _header;
			_header->_left = _header->_right = root;

			
			root->_color = BLACK;
			return true;
		}
		Node* cur = _header->_parent;	
		Node* parent = nullptr;
		while (cur){	

			parent = cur;	

			if (cur->_kv.first == kv.first){	

				return false;
			}
			else if (cur->_kv.first > kv.first){ 

				cur = cur->_left;		
			}
			else{
				cur = cur->_right;		
			}
		}
		
		cur = new Node(kv);
		
		if (parent->_kv.first > cur->_kv.first)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;	
		
		while (cur != _header->_parent && cur->_parent->_color == RED){

			parent = cur->_parent;		
			Node* gfather = parent->_parent;
			
			if (gfather->_left == parent){

				Node* uncle = gfather->_right;
				
				if (uncle&&uncle->_color == RED){

					parent->_color = uncle->_color = BLACK;	
					gfather->_color = RED;
					
					cur = gfather;
				}
				else{

					
					if (cur == parent->_right){
						
						RotateL(parent);
						
						swap(cur, parent);
					}
				
					RotateR(gfather);
					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}
		
			else{
				
				Node* uncle = gfather->_left;
				if (uncle&&uncle->_color == RED){

					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					cur = gfather;
				}
				else{

					if (cur == parent->_left){

						RotateR(parent);
						swap(cur, parent);
					}
					RotateL(gfather);

					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}
		}
		
		_header->_parent->_color = BLACK;

		_header->_left = leftMost();
		_header->_right = rightMost();
	}
