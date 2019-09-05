

#pragma once

#include "wallet/common.h"
#include "wallet/wallet_db.h"

#include <condition_variable>
#include <boost/optional.hpp>
#include "utility/logger.h"

namespace grimm::wallet
{
    class BaseTransaction;

    class AssetIssueTxBuilder : public std::enable_shared_from_this<AssetIssueTxBuilder>
    {
    public:
        AssetIssueTxBuilder(BaseTransaction& tx, SubTxID subTxID, const AmountList& amount, Amount fee, grimm::AssetID assetId, ECC::Scalar::Native skAsset);

        void SelectInputs();
        void AddChange();
        void GenerateChangeCoin(Amount amount);
        void GenerateAssetCoin(Amount amount, grimm::AssetID assetId);
        bool CreateOutputs();
        bool FinalizeOutputs();
        bool LoadKernel();
        bool HasKernelID() const;
        void CreateKernel();
        void GenerateOffset();
        void GenerateNonce();
        virtual ECC::Point::Native GetPublicExcess() const;
        ECC::Point::Native GetPublicNonce() const;
        bool GetInitialTxParams();
        bool GetInputs();
        bool GetOutputs();
        bool GetPeerPublicExcessAndNonce();
        bool GetPeerSignature();
        bool GetPeerInputsAndOutputs();
        void FinalizeSignature();
        bool CreateInputs();
        void FinalizeInputs();
        virtual Transaction::Ptr CreateTransaction();
        void SignPartial();
        bool IsPeerSignatureValid() const;

        Amount GetAmount() const;
        const AmountList& GetAmountList() const;
        Amount GetFee() const;
        Height GetLifetime() const;
        Height GetMinHeight() const;
        virtual Height GetMaxHeight() const;
        const std::vector<Input::Ptr>& GetInputs() const;
        const std::vector<Output::Ptr>& GetOutputs() const;
        const ECC::Scalar::Native& GetOffset() const;
        const ECC::Scalar::Native& GetPartialSignature() const;
        const TxKernel& GetKernel() const;
        const Merkle::Hash& GetKernelID() const;
        void StoreKernelID();
        std::string GetKernelIDString() const;
        bool UpdateMaxHeight();
        bool IsAcceptableMaxHeight() const;
        ECC::Hash::Value GetLockImage() const;
        SubTxID GetSubTxID() const;

        const std::vector<Coin::ID>& GetInputCoins() const;
        const std::vector<Coin::ID>& GetOutputCoins() const;

    protected:
        BaseTransaction& m_Tx;
        SubTxID m_SubTxID;
        grimm::AssetID _assetId;
        ECC::Scalar::Native _skAsset;

        // input
        AmountList m_AmountList;
        Amount m_Fee;
        Amount m_Change;
        Height m_Lifetime;
        Height m_MinHeight;
        Height m_MaxHeight;
        std::vector<Input::Ptr> m_Inputs;
        std::vector<Output::Ptr> m_Outputs;
        ECC::Scalar::Native m_Offset; // goes to offset

        std::vector<Coin::ID> m_InputCoins;
        std::vector<Coin::ID> m_OutputCoins;
        size_t m_NonceSlot = 0;
        ECC::Point::Native m_PublicNonce;

        // peer values
        ECC::Scalar::Native m_PartialSignature;
        ECC::Point::Native m_PeerPublicNonce;
        ECC::Point::Native m_PeerPublicExcess;
        std::vector<Input::Ptr> m_PeerInputs;
        std::vector<Output::Ptr> m_PeerOutputs;
        ECC::Scalar::Native m_PeerOffset;
        Height m_PeerMaxHeight;
        std::unique_ptr<ECC::Hash::Value> m_PeerLockImage;

        // deduced values,
        TxKernel::Ptr m_Kernel;
        TxKernel::Ptr m_EmissionKernel;

        ECC::Scalar::Native m_PeerSignature;
        ECC::Hash::Value m_Message;

        mutable boost::optional<Merkle::Hash> m_KernelID;
        io::AsyncEvent::Ptr m_AsyncCompletedEvent;
    };
}
