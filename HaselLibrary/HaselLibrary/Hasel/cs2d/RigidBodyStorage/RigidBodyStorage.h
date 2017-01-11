#pragma once

#include<list>
#include<map>
#include<sstream>

#include"HaselAlias.h"

namespace hasel
{
	namespace cs2d
	{
		class RigidBody;
		class RigidBodyMold;

		/// <summary>
		/// 剛体インスタンス保管クラス
		/// </summary>
		class RigidBodyStorage
		{
		private:
			//剛体リスト
			std::list<sptr<RigidBody>> rigidBodyies;
			//グルーピング済み剛体リスト <剛体の属性,剛体>
			std::map<int, std::list<wptr<RigidBody>>> groupedRigidBodies;

		public:
			/// <summary>
			/// 剛体インスタンスを作成する
			/// </summary>
			/// <param name="mold">作成に使用する剛体鋳型</param>
			/// <returns>作成された剛体への弱参照</returns>
			wptr<RigidBody> CreateRigidBody(const RigidBodyMold& mold);

			/// <summary>
			/// 剛体インスタンスを削除する
			/// </summary>
			/// <param name="body">削除する剛体インスタンスへの弱参照</param>
			void DestroyRigidBody(const wptr<RigidBody>& body);

			/// <summary>
			/// 剛体インスタンスリストを取得する
			/// </summary>
			/// <returns>剛体インスタンスリスト</returns>
			std::list<wptr<RigidBody>> GetRigidBodies()const;

			/// <summary>
			/// 剛体インスタンスリストを取得する(属性指定)
			/// </summary>
			/// <param name="attribute">指定する属性</param>
			/// <returns>剛体インスタンスリスト</returns>
			const std::list<wptr<RigidBody>>& GetRigidBodies(int attribute)const;
		};
	}
}